#ifndef COUCHBASEADAPTER_GLOBAL_H
#define COUCHBASEADAPTER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(COUCHBASEADAPTER_LIBRARY)
#  define COUCHBASEADAPTERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define COUCHBASEADAPTERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // COUCHBASEADAPTER_GLOBAL_H
