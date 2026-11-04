
undefined4 FUN_005b9490(undefined4 *param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  iVar1 = *(int *)(DAT_00ef1b8c + 8);
  puVar2 = &DAT_00f073d8;
  puVar3 = (undefined4 *)(*(int *)(DAT_00ef1b84 + 8) + 0x14);
  do {
    FUN_00586200(&local_c,puVar2 + 0xc,param_1);
    FUN_00586170(&local_18,puVar2,param_1);
    puVar3[-1] = local_18;
    puVar2 = puVar2 + 0x68;
    *puVar3 = local_14;
    puVar3[1] = local_10;
    puVar3[3] = local_c;
    puVar3[4] = local_8;
    puVar3[5] = local_4;
    puVar3 = puVar3 + 0x1c;
  } while ((int)puVar2 < 0xf07648);
  *(undefined4 *)(DAT_00ef1b84 + 0xc) = 1;
  *(undefined4 *)(iVar1 + 0x80) = *param_1;
  *(undefined4 *)(iVar1 + 0x84) = param_1[4];
  *(undefined4 *)(iVar1 + 0x88) = param_1[8];
  *(undefined4 *)(iVar1 + 0x8c) = param_1[0xc];
  *(undefined4 *)(iVar1 + 0x90) = param_1[1];
  *(undefined4 *)(iVar1 + 0x94) = param_1[5];
  *(undefined4 *)(iVar1 + 0x98) = param_1[9];
  *(undefined4 *)(iVar1 + 0x9c) = param_1[0xd];
  *(undefined4 *)(iVar1 + 0xa0) = param_1[2];
  *(undefined4 *)(iVar1 + 0xa4) = param_1[6];
  *(undefined4 *)(iVar1 + 0xa8) = param_1[10];
  *(undefined4 *)(iVar1 + 0xac) = param_1[0xe];
  *(undefined4 *)(DAT_00ef1b8c + 0xc) = 1;
  return 0;
}

