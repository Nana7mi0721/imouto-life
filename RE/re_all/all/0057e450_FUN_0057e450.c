
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0057e450(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar4 = 0;
  if (param_3 == 0) {
    return 0;
  }
  puVar1 = (undefined4 *)(param_1 + 0x178);
  if (param_2 != 0) {
    puVar5 = (undefined4 *)(param_2 + 0x178);
    puVar6 = puVar1;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar5 = (undefined4 *)(param_2 + 0x114);
    puVar6 = (undefined4 *)(param_1 + 0x114);
    for (iVar4 = 0x19; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    *(undefined4 *)(param_1 + 0x114) = puVar1;
    *(int *)(param_1 + 0x158) = param_1 + 0x198;
    return 0;
  }
  *(undefined4 **)(param_1 + 0x114) = puVar1;
  *puVar1 = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 4) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 8) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 0xc) = 0x3f800000;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 0x10) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 0x14) = 0x3f800000;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 0x18) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 0x1c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x120) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x128) = 0x3f800000;
  puVar5 = (undefined4 *)(param_1 + 0x198);
  *(undefined4 **)(param_1 + 0x158) = puVar5;
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined ***)(param_1 + 0x15c) = &PTR_DAT_007d8568;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined ***)(param_1 + 0x160) = &PTR_DAT_007d85a8;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined ***)(param_1 + 0x16c) = &PTR_DAT_007d85c8;
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  *(undefined4 *)(param_1 + 0x154) = _DAT_007d5504;
  uVar2 = _DAT_007d103c;
  *(undefined4 *)(param_1 + 0x148) = _DAT_007d103c;
  *(undefined4 *)(param_1 + 0x14c) = _DAT_007d97a0;
  uVar3 = _DAT_007d63bc;
  *(undefined4 *)(param_1 + 0x170) = _DAT_007d63bc;
  *(undefined4 *)(param_1 + 0x174) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xa4) = *puVar1;
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0x17c);
  *(uint *)(param_1 + 0x150) = (uint)*(ushort *)(param_1 + 0x32);
  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0x180);
  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0x184);
  *(undefined4 *)(param_1 + 0xb4) = uVar3;
  *(undefined4 *)(param_1 + 0xb8) = uVar2;
  if (*(ushort *)(param_1 + 0x32) != 0) {
    do {
      *puVar5 = 0;
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar4 < (int)(uint)*(ushort *)(param_1 + 0x32));
  }
  return 0;
}

