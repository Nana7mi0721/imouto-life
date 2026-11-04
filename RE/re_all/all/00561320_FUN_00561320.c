
undefined4 FUN_00561320(uint param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 local_4;
  
  if (DAT_00a834f0 == 0) {
    return 0xffffffff;
  }
  iVar1 = FUN_0057e0e0();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    if (DAT_00cc4db0 == 0) {
      return 0;
    }
    if ((int)param_1 < 0) {
      return 0;
    }
    if ((param_1 & 0x7c000000) != DAT_00cc4dd8) {
      return 0;
    }
    if (DAT_00cc4de0 <= (int)(param_1 & 0xffff)) {
      return 0;
    }
    piVar2 = *(int **)(DAT_00cc4db4 + (param_1 & 0xffff) * 4);
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    if (*piVar2 * 0x10000 != (param_1 & 0x3ff0000)) {
      return 0;
    }
    if (piVar2[4] != 0) {
      return 0;
    }
  }
  else {
    if (DAT_00cc4db0 == 0) {
      return 0;
    }
    if ((int)param_1 < 0) {
      return 0;
    }
    if ((param_1 & 0x7c000000) != DAT_00cc4dd8) {
      return 0;
    }
    if (DAT_00cc4de0 <= (int)(param_1 & 0xffff)) {
      return 0;
    }
    piVar2 = *(int **)(DAT_00cc4db4 + (param_1 & 0xffff) * 4);
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    if (*piVar2 * 0x10000 != (param_1 & 0x3ff0000)) {
      return 0;
    }
  }
  if (piVar2[0x482] == 1) {
    if ((param_2 == 0) && (iVar1 = FUN_005606e0(param_1), iVar1 == 1)) {
      return 0;
    }
    iVar1 = FUN_0055fa80(param_1,piVar2,&local_4,0);
    if ((iVar1 != -1) && ((char)piVar2[0x935] != '\x01')) {
      FUN_00551d10(local_4,0);
      piVar2[0x48a] = -800;
      piVar2[0x48b] = -1;
      piVar2[0x934] = 0;
      *(undefined1 *)((int)piVar2 + 0x24d5) = 0;
      FUN_00596ef0(piVar2 + piVar2[0x92e] * 0x128 + 0x499,
                   piVar2[0x930] / (int)(uint)*(ushort *)(piVar2 + 0x480));
      FUN_0056da60(&DAT_00cc4df4,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x562);
      *(undefined1 *)(piVar2 + 0x935) = 1;
      FUN_0056dac0(&DAT_00cc4df4);
      FUN_005607a0(param_1,param_2);
    }
  }
  return 0;
}

