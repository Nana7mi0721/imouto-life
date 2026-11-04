
longlong FUN_006bde70(byte *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  if (param_3 < 0) {
    return -1;
  }
  lVar3 = __allshr();
  uVar4 = __allshl();
  uVar2 = param_2 - (uint)uVar4;
  if ((*param_1 < 4) &&
     ((*param_1 != 3 || ((param_1[1] < 3 && ((param_1[1] != 2 || (param_1[2] == 0)))))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return lVar3 + CONCAT44(((param_3 - (int)((ulonglong)uVar4 >> 0x20)) -
                          (uint)(param_2 < (uint)uVar4)) - (uint)(uVar2 < uVar1),uVar2 - uVar1);
}

