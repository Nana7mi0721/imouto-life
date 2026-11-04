
undefined4 FUN_005b89a0(uint param_1)

{
  if (DAT_00f2eaac < param_1) {
    FUN_0056e1d0(DAT_00f2eaa8);
    DAT_00f2eaa8 = 0;
    DAT_00f2eaac = 0;
    DAT_00f2eaa8 = FUN_0056e030(param_1,
                                "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp"
                                ,0xd5b);
    if (DAT_00f2eaa8 == 0) {
      FUN_0056bca0(&DAT_007fd070);
      return 0xffffffff;
    }
    DAT_00f2eaac = param_1;
  }
  return 0;
}

