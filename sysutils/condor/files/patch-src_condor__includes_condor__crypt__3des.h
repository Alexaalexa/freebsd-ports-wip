--- src/condor_includes/condor_crypt_3des.h.orig	2016-09-29 11:34:28 UTC
+++ src/condor_includes/condor_crypt_3des.h
@@ -61,7 +61,7 @@ class Condor_Crypt_3des : public Condor_
     //------------------------------------------
     // Private constructor
     //------------------------------------------
-    des_key_schedule  keySchedule1_, keySchedule2_, keySchedule3_;
+    DES_key_schedule  keySchedule1_, keySchedule2_, keySchedule3_;
     unsigned char     ivec_[8];
     int               num_;
 };
