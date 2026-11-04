
/* WARNING: Removing unreachable block (ram,0x006c246f) */

longlong FUN_006c23f0(uint param_1,int param_2,uint param_3,int param_4,uint param_5,
                     undefined4 param_6)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = CONCAT44(param_2,param_1);
  if ((param_4 <= param_2) && ((param_4 < param_2 || (param_3 <= param_1)))) {
    return CONCAT44(param_6,param_5);
  }
  if ((param_2 < 1) && ((param_2 < 0 || (param_1 == 0)))) {
    return 0;
  }
  lVar3 = __allshr();
  param_1 = 0x3f;
  do {
    uVar1 = __allshl();
    if (lVar4 < lVar3) {
      lVar4 = __allshl();
    }
    else {
      lVar4 = __allmul(lVar4,2,0);
      lVar4 = lVar4 - CONCAT44(param_4,param_3);
      uVar1 = uVar1 | 1;
    }
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  uVar2 = 0;
  param_3 = 0x3f;
  do {
    if ((uVar1 & 1) == 0) {
      lVar4 = __allshr();
    }
    else {
      lVar3 = __allshr();
      lVar4 = __allshr();
      lVar4 = lVar4 + lVar3 + (ulonglong)(uVar2 & param_5 & 1);
    }
    uVar2 = (uint)lVar4;
    uVar1 = __allshr();
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  return lVar4;
}

