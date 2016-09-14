# QTCouchBaseLib
Qt envelope over the CouchBase C++ client lib

.
├── BIN(Binaries+Libs)
│   ├── Debug
│   │   ├── Platform #1
│   │   │   ├──Bin (.exe)
│   │   │   ├──Lib (.dll)
│   │   │   └──Resources (.res)
│   │   └── ...
│   └── Release
│       └── ...
│
├── TEMP(MOC, Obj, Rcc, Ui-files)
│   ├── Debug
│   │   ├── Platform #1
│   │   └── ...
│   └── Release
│       ├── Platform #1
│       └── ...
│
└── Import (external Libs)
    ├── Platform
    │   ├──Bin (Debug + Release)
    │   ├──Lib (Debug + Release)
    │   └──Include
    └── ...
