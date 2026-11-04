
undefined4 FUN_005ed8e0(int param_1)

{
  int iVar1;
  
  if (DAT_00f3a1c4 < param_1) {
    if (DAT_00f3a1c0 != 0) {
      FUN_0056e1d0(DAT_00f3a1c0);
      DAT_00f3a1c0 = 0;
      DAT_00f3a1c4 = 0;
    }
    iVar1 = ((int)(param_1 + 0x400f + (param_1 + 0x400f >> 0x1f & 0xfU)) >> 4) << 4;
    DAT_00f3a1c0 = FUN_0056e030(iVar1,
                                "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D11.cpp",
                                0x57);
    if (DAT_00f3a1c0 == 0) {
      FUN_0056bca0(&DAT_008025b0,iVar1);
      return 0xffffffff;
    }
    DAT_00f3a1c4 = iVar1;
  }
  return 0;
}

