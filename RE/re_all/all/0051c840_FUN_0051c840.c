
undefined4 FUN_0051c840(uint param_1,uint param_2)

{
  int iVar1;
  
  if (2 < param_1) {
    return 0xffffffff;
  }
  if ((uint)(&DAT_00a37f80)[param_1] < param_2) {
    iVar1 = FUN_0056e1b0((&DAT_00a37f74)[param_1],param_2,
                         "..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp",0x81c7);
    (&DAT_00a37f74)[param_1] = iVar1;
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    (&DAT_00a37f80)[param_1] = param_2;
  }
  return 0;
}

