
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_006c5af0(double param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ushort in_FPUControlWord;
  float10 fVar4;
  double dVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  
  if ((DAT_00f488dc != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    uVar2 = (uint)((ulonglong)param_1 >> 0x20);
    uVar1 = uVar2 >> 0x14;
    lVar6 = CONCAT44(_UNK_008326b4,_DAT_008326b0 - (uVar2 >> 0x14 & _DAT_008326e0));
    if ((uVar1 & 0x800) == 0) {
      if (uVar1 < 0x3ff) {
        return (float10)0;
      }
      if (uVar1 < 0x433) {
        return (float10)(double)(((ulonglong)param_1 >> lVar6) << lVar6);
      }
    }
    else {
      dVar5 = (double)(((ulonglong)param_1 >> lVar6) << lVar6);
      if (uVar1 < 0xbff) {
        return (float10)(double)((-(ulonglong)(param_1 < _DAT_008326d0) | (ulonglong)_DAT_008326d0)
                                & _DAT_008326c0);
      }
      if (uVar1 < 0xc33) {
        return (float10)(dVar5 - (double)(-(ulonglong)(param_1 < dVar5) & _DAT_008326a0));
      }
    }
    if (NAN(param_1)) {
      ___libm_error_support(&param_1,&param_1,&param_1,0x3ed);
    }
    return (float10)(double)CONCAT26(param_1._6_2_,param_1._0_6_);
  }
  uVar2 = __ctrlfp(DAT_00a0f634,0xffff);
  if ((param_1._6_2_ & 0x7ff0) == 0x7ff0) {
    iVar3 = __sptype();
    if (0 < iVar3) {
      if (iVar3 < 3) {
        __ctrlfp(uVar2,0xffff);
        return (float10)(double)CONCAT26(param_1._6_2_,param_1._0_6_);
      }
      if (iVar3 == 3) {
        fVar4 = (float10)__handle_qnan1();
        return fVar4;
      }
    }
    dVar5 = (double)CONCAT26(param_1._6_2_,param_1._0_6_) + _DAT_00802e18;
    uVar8 = CONCAT26(param_1._6_2_,param_1._0_6_);
    uVar7 = 8;
  }
  else {
    fVar4 = (float10)__frnd((int)param_1._0_6_,(int)(CONCAT26(param_1._6_2_,param_1._0_6_) >> 0x20))
    ;
    dVar5 = (double)fVar4;
    if ((dVar5 == (double)CONCAT26(param_1._6_2_,param_1._0_6_)) || ((uVar2 & 0x20) != 0)) {
      __ctrlfp(uVar2,0xffff);
      return (float10)dVar5;
    }
    uVar8 = CONCAT26(param_1._6_2_,param_1._0_6_);
    uVar7 = 0x10;
  }
  fVar4 = (float10)__except1(uVar7,0xb,uVar8,dVar5,uVar2);
  return fVar4;
}

