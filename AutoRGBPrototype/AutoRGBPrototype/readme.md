# AutoRGB Sample Overview

### Description

This sample demonstrates how to extract a single, representative ambient 
color from a desktop screen and use it to illuminate LED lamps on connected
RGB devices that fit the HID standard via the Windows.Devices.Lights API. 
This sample requires the C++/WinRT, Windows App SDK, WinUI, and Windows 
Implementation Library packages. 

### Building the Sample
Deploy the app. Click on the "Capture screen" button to begin the screen
capture that calculates the ambient color to display. Watch your 
lighting devices illuminate with the ambient color! Try it on videos,
games, and more. The app will display the calculated color as well. Note
that if you are using a multi-monitor setup, the monitor with the active
window will be the one captured. Note that the sample app has to be in
foreground in order for it to work. 

### Implementation Notes
There are 4 main components to this sample: screen capture, compute shader,
ambient color algorithm, and RGB device manager. 

##### Screen Capture
The screen capture is done via the Windows.Graphics.Capture API. We use
D3D11 in this sample. The monitor that contains the active window is the
screen that will be captured. A screen capture is taken whenever a change
is detected on the monitor display (e.g. resizing a window). This code
is part of the GraphicsManager class. 

##### Compute Shader
We convert the capture to a 2D texture to input into a compute shader. 
The compute shader's purpose is to create 3 histograms - one for each of
the R, G, and B color spaces. The shader analyzes each pixel of the texture
and plots its R value on the R histogram, its G value on the G histogram, 
and its B value on the B histogram. Each histogram has 8 buckets, so pixels 
are plotted into 1 of 8 buckets based on its value: 0-31, 32-63,..., 224-255. 
This code is located in 2 files: Color.hlsl and the GraphicsManager class. 
The GraphicsManager class runs the shader whenever a capture is taken. 

##### Ambient Color Algorithm
The ambient color algorithm calculates the most predominant color on the
screen by analyzing the R, G, and B histograms output by the shader. The
algorithm looks at 2 color heuristics: top X buckets and weighted average. 

1. Top X Buckets: To calculate this heuristic, we start by looking at the 
highest bucket of each of the three histograms. If the number of pixels in 
this bucket surpasses a set threshold, then only this bin will be used to 
calculate the ambient color. If not, then the next bin is added and so on 
until we meet the threshold. The idea of this heuristic is to give more 
weight to the colors that have higher intensity pixels while also adapatively 
changing the number of bins to account for the pixel count. 

2. Weighted Average: This heuristic takes the weighted average of the 3 
histograms and normalizes the result. It gives similar results for well-lit
scenes but exaggerates colors on dimmer, darker scenes. 

To calculate the ambient color, we look at the color produced by both of 
the above heuristics and then calculate a color that is in-between the 2. 
When the ambient color is calculated, we raise an event that the MainWindow
class subscribes to. When the MainWindow class receives this event, it
updates the color shown on the app window and on all connected RGB devices.

##### RGB Device Manager
The RGBDeviceManager class listens for when a HID-compliant device is 
added or removed and controls the colors shown on the devices. The MainWindow
class maintains an instance of the RGBDeviceManager and instructs it to change
the color on all connected devices whenever the event is raised.

### Additional Notes
This sample was created in collaboration with the Xbox team. 

========================================================================
Learn more about Windows App SDK here:
https://docs.microsoft.com/windows/apps/windows-app-sdk/
Learn more about WinUI3 here:
https://docs.microsoft.com/windows/apps/winui/winui3/
Learn more about C++/WinRT here:
http://aka.ms/cppwinrt/
Learn more about Windows.Devices.Lights here: 
https://learn.microsoft.com/en-us/uwp/api/windows.devices.lights?view=winrt-22621
Learn more about Windows.Graphics.Capture here:
https://learn.microsoft.com/en-us/windows/uwp/audio-video-camera/screen-capture
Learn more about compute shaders here: 
https://learn.microsoft.com/en-us/windows/win32/direct3d11/direct3d-11-advanced-stages-compute-shader
========================================================================
