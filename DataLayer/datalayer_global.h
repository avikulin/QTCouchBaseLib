#ifndef DATALAYER_GLOBAL_H
#define DATALAYER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DATALAYER_LIBRARY)
#  define DATALAYERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DATALAYERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DATALAYER_GLOBAL_H
