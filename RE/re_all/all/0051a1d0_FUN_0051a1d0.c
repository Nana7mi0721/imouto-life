
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0051a1d0(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  
  if (DAT_00a49730 == 0) {
    uVar1 = (uint)(DAT_00a37d7c == 0);
  }
  else {
    uVar1 = DAT_00a37d78;
  }
  *param_1 = uVar1;
  param_1[1] = 0;
  param_1[2] = DAT_00a37ed8;
  param_1[3] = DAT_00a37edc;
  param_1[4] = DAT_00a37ee0;
  param_1[5] = DAT_00a380cc;
  param_1[6] = DAT_00a380d0;
  param_1[7] = DAT_00a380bc;
  param_1[8] = (uint)(DAT_00a37ebc == 0);
  param_1[9] = DAT_00a38120;
  puVar3 = &DAT_00a38358;
  puVar4 = param_1 + 10;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  param_1[0x8a] = DAT_00a384e0;
  *(undefined8 *)(param_1 + 0x8c) = _DAT_00a38500;
  *(undefined8 *)(param_1 + 0x8e) = _DAT_00a38508;
  puVar3 = &DAT_00a38510;
  puVar4 = param_1 + 0x96;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  *(undefined8 *)(param_1 + 0x90) = _DAT_00a384e8;
  *(undefined8 *)(param_1 + 0x92) = _DAT_00a384f0;
  *(undefined8 *)(param_1 + 0x94) = _DAT_00a384f8;
  puVar3 = &DAT_00a38420;
  puVar4 = param_1 + 0x2a;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar3 = &DAT_00a38718;
  puVar4 = param_1 + 0x4a;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar3 = &DAT_00a38290;
  puVar4 = param_1 + 0x6a;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  param_1[0xb6] = DAT_00a38194;
  param_1[0xb7] = DAT_00a38198;
  param_1[0xb8] = DAT_00a3819c;
  param_1[0xb9] = DAT_00a381a0;
  return 0;
}

