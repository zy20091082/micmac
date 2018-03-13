cmake_minimum_required(VERSION 2.8)

#set(Qt5Core_DIR "C:/Qt/5.6/msvc2013_64/lib/cmake/Qt5Core")
#set(Qt5_DIR "C:/Qt/5.6/msvc2013_64/lib/cmake/Qt5")
#set(QT_QMAKE_EXECUTABLE "C:/Qt/5.6/msvc2013_64/bin/qmake.exe")

 QT5_WRAP_CPP(HEADERS_moced
/home/atruffier/micmac/src/GI_MicMac/Aperi.h
/home/atruffier/micmac/src/GI_MicMac/Bascule.h
/home/atruffier/micmac/src/GI_MicMac/C3dc.h
/home/atruffier/micmac/src/GI_MicMac/Campari.h
/home/atruffier/micmac/src/GI_MicMac/Cmd.h
/home/atruffier/micmac/src/GI_MicMac/CropRPC.h
/home/atruffier/micmac/src/GI_MicMac/ChSys.h
/home/atruffier/micmac/src/GI_MicMac/GrShade.h
/home/atruffier/micmac/src/GI_MicMac/Console.h
/home/atruffier/micmac/src/GI_MicMac/Convert2GenBundle.h
/home/atruffier/micmac/src/GI_MicMac/SaisiePts.h
/home/atruffier/micmac/src/GI_MicMac/MainWindow.h
/home/atruffier/micmac/src/GI_MicMac/Malt.h
/home/atruffier/micmac/src/GI_MicMac/Meshlab.h
/home/atruffier/micmac/src/GI_MicMac/MM2DPosSism.h
/home/atruffier/micmac/src/GI_MicMac/SaisieMasq.h
/home/atruffier/micmac/src/GI_MicMac/Sel.h
/home/atruffier/micmac/src/GI_MicMac/Tapas.h
/home/atruffier/micmac/src/GI_MicMac/Tapioca.h
/home/atruffier/micmac/src/GI_MicMac/Tarama.h
)

ADD_EXECUTABLE(interfaceMicmac
/home/atruffier/micmac/src/GI_MicMac/Aperi.cpp
/home/atruffier/micmac/src/GI_MicMac/Bascule.cpp
/home/atruffier/micmac/src/GI_MicMac/C3dc.cpp
/home/atruffier/micmac/src/GI_MicMac/Campari.cpp
/home/atruffier/micmac/src/GI_MicMac/Cmd.cpp
/home/atruffier/micmac/src/GI_MicMac/CropRPC.cpp
/home/atruffier/micmac/src/GI_MicMac/ChSys.cpp
/home/atruffier/micmac/src/GI_MicMac/Console.cpp
/home/atruffier/micmac/src/GI_MicMac/Convert2GenBundle.cpp
/home/atruffier/micmac/src/GI_MicMac/SaisiePts.cpp
/home/atruffier/micmac/src/GI_MicMac/GrShade.cpp
/home/atruffier/micmac/src/GI_MicMac/main.cpp
/home/atruffier/micmac/src/GI_MicMac/MainWindow.cpp
/home/atruffier/micmac/src/GI_MicMac/Malt.cpp
/home/atruffier/micmac/src/GI_MicMac/Meshlab.cpp
/home/atruffier/micmac/src/GI_MicMac/MM2DPosSism.cpp
/home/atruffier/micmac/src/GI_MicMac/NewProject.cpp
/home/atruffier/micmac/src/GI_MicMac/SaisieMasq.cpp
/home/atruffier/micmac/src/GI_MicMac/Sel.cpp
/home/atruffier/micmac/src/GI_MicMac/Tapas.cpp
/home/atruffier/micmac/src/GI_MicMac/Tapioca.cpp
/home/atruffier/micmac/src/GI_MicMac/Tarama.cpp
${HEADERS_moced}
)


TARGET_LINK_LIBRARIES(interfaceMicmac elise ${X11_LIBRARIES} ${QT_LIBRARIES} ${OPENGL_LIBRARIES} ${KAKADU_LIBRARIES})

#INSTALL(TARGETS interfaceMicmac RUNTIME DESTINATION ${Install_Dir})
