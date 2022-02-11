# Scholes_DronePose_Network
Unreal Environment:
Note that the Unreal environment does not contain drone models, materials, or textures, since they are too large to be hosted on Github. Instead a default cube and sphere have been placed in the environment to demonstrate data capture. High fidelity drone models can be obtained from any suitable 3D model source and the necessary materials created within Unreal. 
The Virtual environment is controlled by three blueprints, “BP_Spad”, “SPADPixel” and, the level blueprint. The first two blueprints are located in …/content/SPAD, while the level blueprint can be accessed by going to the “Blueprints” tab within the editor and selecting “Open Level Blueprint”. BP_Spad creates an array of pixels (each pixel is controlled by SPADPixel). BP_Spad takes as input the range to target, the half-field-of-view in x and y, and, the number of pixels in x and y. The blueprint calculates the angle at which the ray from each pixel must be projected such that an area defined by twice the half-field-of-view in each direction is sampled by the number of pixels in that direction. BP_Spad also saves the intensity image defined by the same half-field-of-view to the filepath specified by the variable “Intensity Image File Path”. Note that spawning many pixels is computationally expensive and will slow frame acquisition.
SPADPixel defines each pixel in the SPAD array. Each pixel relies on the “MultiLineTraceByChannel” node in Unreal, this projects a ray from an origin along a vector and reports what it strikes. The vector along which the ray is projected is defined by BP_Spad. For each “hit” of the ray, the distance along the vector as well as the physical material impacted is recorded. This result is then passed through a series of if statements resulting in a string which records the distance and a one-hot vector for the material. In this way, by assigning different physical materials to different components in the drone, segmentation can be performed. This string is then saved using the “Save Array” node which is a custom node derived from the c++ class found in …/Source/Attempt_1/Private/TextFileManager.
Finally, the level blueprint is responsible for adjusting (and recording) the position and orientation of the object imaged by the SPAD array. For each frame, the level blueprint will locate and orient the object at a random value within a range, this value as well as the bounding box of the object are then captured in a string vector which is recorded using the “Save Array” node.
The segmentation is performed by creating a “Physical Material” with a name “x” in the engine. This physical material can then be attached to a rendering material using the “Phys material” slot. This allows for segmentation without effecting the photo-realistic nature of the image capture.
