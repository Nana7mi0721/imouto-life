
undefined4 FUN_004175e0(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0x10) {
    uVar1 = FUN_004175d0(param_1,param_3,param_4);
  }
  else {
    if ((param_2 == 0x111) && ((param_3 & 0xffff) == 0x3ed)) {
      FUN_0050eab0(1);
      FUN_00436600();
      FUN_0050eab0(DAT_00a117a4);
      SetFocus(DAT_00a0f80c);
      SetFocus(DAT_00a0f804);
    }
    uVar1 = 0;
  }
  return uVar1;
}

