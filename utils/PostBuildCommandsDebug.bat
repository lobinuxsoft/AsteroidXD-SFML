set ProjectDir=%~1
set TargetDir=%~2
set DLLDir=%~3

xcopy "%ProjectDir%resources\" "%TargetDir%resources\" /E /Y
copy "%DLLDir%\openal32.dll" "%TargetDir%openal32.dll" /Y
copy "%DLLDir%\sfml-audio-d-2.dll" "%TargetDir%sfml-audio-d-2.dll" /Y
copy "%DLLDir%\sfml-graphics-d-2.dll" "%TargetDir%sfml-graphics-d-2.dll" /Y
copy "%DLLDir%\sfml-network-d-2.dll" "%TargetDir%sfml-network-d-2.dll" /Y
copy "%DLLDir%\sfml-system-d-2.dll" "%TargetDir%sfml-system-d-2.dll" /Y
copy "%DLLDir%\sfml-window-d-2.dll" "%TargetDir%sfml-window-d-2.dll" /Y