
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0052b2d0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_88 [33];
  
  DAT_00a37ee0 = param_1[4];
  DAT_00a37edc = param_1[3];
  DAT_00a37ed8 = param_1[2];
  DAT_00a37ed4 = 1;
  if (DAT_00a37d78 != 0) {
    FUN_005e2310(DAT_00a37ed8,DAT_00a37edc,DAT_00a37ee0);
  }
  FUN_005160d0(param_1[5],param_1[6]);
  iVar1 = param_1[7];
  if ((iVar1 != DAT_00a380bc) && (DAT_00a3d360 = 1, DAT_00a380bc = iVar1, DAT_00a37d78 != 0)) {
    FUN_00567b90(iVar1);
  }
  if ((DAT_00a37dd8 != 0) || (DAT_00a49730 != 1)) {
    DAT_00a37ebc = (uint)(param_1[8] == 0);
    FUN_005e2310(param_1[8]);
  }
  FUN_0052a4a0(param_1[9]);
  if (DAT_00a49730 != 1) {
    DAT_00a37d7c = (uint)(*param_1 == 0);
  }
  FUN_005217e0(param_1[0xb6],param_1[0xb7],param_1[0xb8],param_1[0xb9]);
  FUN_00521bf0(param_1 + 0x6a);
  FUN_00521cd0(param_1 + 10);
  iVar1 = param_1[0x8a];
  if (iVar1 == 0) {
    _DAT_00a38500 = *(undefined8 *)(param_1 + 0x8c);
    DAT_00a384e0 = 0;
  }
  else if (iVar1 == 1) {
    _DAT_00a38508 = *(undefined8 *)(param_1 + 0x8e);
    DAT_00a384e0 = 1;
  }
  else {
    if (iVar1 != 2) goto LAB_0052b446;
    piVar2 = param_1 + 0x96;
    piVar3 = local_88;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    DAT_00a384e0 = 2;
    piVar2 = local_88;
    piVar3 = &DAT_00a38510;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
  }
  FUN_00524b70();
LAB_0052b446:
  _DAT_00a384f0 = *(undefined8 *)(param_1 + 0x92);
  _DAT_00a384e8 = *(undefined8 *)(param_1 + 0x90);
  FUN_00524b70();
  _DAT_00a384f8 = *(undefined8 *)(param_1 + 0x94);
  FUN_00524b70();
  FUN_00521d40(param_1 + 0x4a);
  return 0;
}

