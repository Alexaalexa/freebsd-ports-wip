# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	huang-pipeline1
PORTVERSION=	0.1
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	RNA sequencing pipeline metaport for Spencer Huang

LICENSE=	BSD3CLAUSE

# Note: tophat depends on bowtie1.  Do we really want both bowties?
RUN_DEPENDS=	star>=0:/usr/wip/biology/star \
		virusseq>=0:/usr/wip/biology/virusseq \
		${PYTHON_PKGNAMEPREFIX}htseq>=0.6.1:/usr/wip/biology/py-htseq

USES=		metaport python

.include <bsd.port.mk>
