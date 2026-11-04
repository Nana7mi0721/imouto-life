
undefined4 FUN_005800e0(int param_1)

{
  if (DAT_00ca3d18 == 0) {
    DAT_00ca3d28 = param_1;
    return 0;
  }
  if (param_1 < 1) {
    param_1 = 1;
  }
  if (DAT_00ca3d24 < param_1) {
    param_1 = DAT_00ca3d24;
  }
  FUN_0056da60(&DAT_00ca4230,"..\\..\\..\\..\\Source\\Library\\Main\\DxASyncLoad.cpp",0x422);
  DAT_00ca3d28 = param_1;
  FUN_0056dac0(&DAT_00ca4230);
  return 0;
}

