# Created by:	Jason Bacon
# $FreeBSD$

PORTNAME=	gcc-gfortran
PORTVERSION=	4.3.2
CATEGORIES=	devel linux
MASTER_SITES=	http://archives.fedoraproject.org/pub/archive/fedora/linux/releases/10/Fedora/i386/os/Packages/
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	GNU Compiler Collection C compiler

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	7

RUN_DEPENDS=	${LINUXBASE}/usr/bin/gcc:../../lang/linux-f10-gcc

.include <bsd.port.mk>
