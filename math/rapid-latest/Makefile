############################################################################
# New ports collection Makefile for:   RAPID
# Date created:        18 July 2006
# Whom:                Jason W. Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#
# The RAPID code is offered "as is" and is free for non-commercial use.
# 
# To use RAPID for any commercial purpose, you must request a license from
# 
# 	http://www.cs.unc.edu/~geom/OBB/OBBT.html
# 
# Redistribution of RAPID code in any form is strictly prohibited.
# 
############################################################################

PORTNAME=	rapid
PORTVERSION=	2.01
CATEGORIES=	math science graphics
MASTER_SITES=	http://www.cs.sunysb.edu/~algorith/implement/RAPID/distrib/ \
		http://www.neuro.mcw.edu/Ports/distfiles/
DISTNAME=	RAPID_v2_01

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Robust and Accurate Polygon Interference Detection

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

ALL_TARGET=

MAN1=	rapid.1

.include <bsd.port.pre.mk>

post-extract:
	${REINPLACE_CMD} -E "s/friend RAPID_Collide/friend int RAPID_Collide/" ${WRKSRC}/RAPID_private.H

do-install:
	${MKDIR} ${PREFIX}/include/RAPID
	${INSTALL_DATA}	${WRKSRC}/*.H ${PREFIX}/include/RAPID
	${INSTALL_DATA}	${WRKSRC}/libRAPID.a ${PREFIX}/lib
	${INSTALL_MAN} ${FILESDIR}/rapid.1 ${MANPREFIX}/man/man1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
