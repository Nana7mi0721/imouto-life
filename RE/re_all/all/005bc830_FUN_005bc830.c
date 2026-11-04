
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005bc830(int param_1)

{
  int *piVar1;
  
  FUN_0056da60(&DAT_00cc7cf4,"..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp",
               0x2691);
  piVar1 = &DAT_00f136b0;
  do {
    if (piVar1[-0xe] == *(int *)(param_1 + 4)) {
      piVar1[-0xe] = 0;
    }
    if (*piVar1 == *(int *)(param_1 + 4)) {
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0xf136e8);
  if (*(int *)(param_1 + 4) != 0) {
    FUN_005d1ec0(*(int *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  if (DAT_00ef1b80 == param_1) {
    DAT_00ef1b80 = *(int *)(param_1 + 0x10);
    if (*(int *)(param_1 + 0x10) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x14) = 0;
    }
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x10) = *(undefined4 *)(param_1 + 0x10);
    if (*(int *)(param_1 + 0x10) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x14) = *(undefined4 *)(param_1 + 0x14);
    }
  }
  FUN_0056e1d0(param_1);
  _DAT_00ef1b7c = _DAT_00ef1b7c + -1;
  FUN_0056dac0(&DAT_00cc7cf4);
  return 0;
}

