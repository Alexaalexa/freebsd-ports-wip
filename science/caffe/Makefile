# Created by: Jason Bacon <bacon@unixdev.ceas.uwm.edu>
# $FreeBSD$

PORTNAME=	caffe
PORTVERSION=	2016.10.20
CATEGORIES=	science

MAINTAINER=	bacon@unixdev.ceas.uwm.edu
COMMENT=	Fast open framework for deep learning

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# FIXME: Probably don't really need devel/libc++.  Added to silence QA.
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy
LIB_DEPENDS+=	libboost_regex.so:devel/boost-libs \
		libboost_python.so:devel/boost-python-libs \
		libc++.so.1:devel/libc++ \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libhdf5.so:science/hdf5 \
		liblmdb.so:databases/lmdb \
		libleveldb.so:databases/leveldb \
		libopenblasp.so:math/openblas \
		libopencv_highgui.so:graphics/opencv2 \
		libopencv_imgproc.so:graphics/opencv2-core \
		libprotobuf.so:devel/protobuf \
		libsnappy.so:archivers/snappy \
		libsz.so:science/szip

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy

USES=		cmake fortran python

USE_GITHUB=	yes
GH_ACCOUNT=	BVLC
GH_TAGNAME=	4ba654f5c88c36ee8ba53964b7faf25c6d7010b4

# FIXME: Add option for atlas instead of openblas
CMAKE_ARGS+=	-DBLAS:STRING="Open"

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

# FIXME: Some python files still being installed outside sitelibdir
post-patch:
	@${REINPLACE_CMD} -e 's|DESTINATION python|DESTINATION ${PYTHON_SITELIBDIR}|g' ${WRKSRC}/python/CMakeLists.txt

.include <bsd.port.mk>
