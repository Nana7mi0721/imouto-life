
undefined4 * __thiscall
FUN_0060b690(undefined4 *param_1,float *param_2,float *param_3,float param_4,float param_5,
            float param_6)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int *piVar6;
  undefined1 *puVar7;
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  param_1[1] = 0xfffffffe;
  param_1[2] = 0x7fffffff;
  param_1[0x19] = param_5;
  param_1[0x1a] = 0;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  *param_1 = &PTR_FUN_00803f90;
  uVar1 = (int)param_4 + 1;
  if (param_5 == 0.0) {
    iVar2 = FUN_00646b30(0x4c,0x10);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_00614f00();
    }
    param_1[0x19] = uVar3;
    *(undefined1 *)(param_1 + 0x1b) = 1;
  }
  if (param_6._0_1_ == '\0') {
    puVar4 = (undefined4 *)FUN_00646b30(0x18,0x10);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      FUN_0060d160();
      FUN_0060d170();
      *puVar4 = &PTR_LAB_00803f20;
    }
    param_1[0x1e] = puVar4;
    iVar2 = FUN_00646b30(0x9c,0x10);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_006132d0(param_1[0x1e]);
    }
    param_1[0x1d] = iVar2;
    *(undefined1 *)(iVar2 + 0x99) = 1;
  }
  param_1[3] = *param_2;
  param_1[4] = param_2[1];
  param_1[5] = param_2[2];
  param_1[6] = param_2[3];
  param_1[7] = *param_3;
  param_1[8] = param_3[1];
  param_1[9] = param_3[2];
  param_1[10] = param_3[3];
  param_6 = (float)param_1[9] - (float)param_1[5];
  param_5 = (float)param_1[8] - (float)param_1[4];
  param_4 = (float)param_1[7] - (float)param_1[3];
  FUN_005fc500(&param_4,&param_5,&param_6);
  puVar7 = local_20;
  param_4 = (float)(uint)param_1[2];
  param_5 = param_4;
  param_6 = param_4;
  uVar3 = FUN_005fc500(&param_4,&param_5,&param_6);
  puVar4 = (undefined4 *)FUN_0060b920(local_10,uVar3,puVar7);
  param_1[0xb] = *puVar4;
  param_1[0xc] = puVar4[1];
  param_1[0xd] = puVar4[2];
  param_1[0xe] = puVar4[3];
  iVar2 = FUN_00646b30(uVar1 * 0x4c,0x10);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    FUN_005f5190(iVar2,0x4c,uVar1,&LAB_0060d0d0);
  }
  uVar5 = 1;
  param_1[0x11] = iVar2;
  param_1[0x10] = uVar1;
  param_1[0xf] = 0;
  param_1[0x12] = 1;
  if (1 < uVar1) {
    iVar2 = 0x4c;
    do {
      uVar5 = uVar5 + 1;
      *(uint *)(iVar2 + 0x30 + param_1[0x11]) = uVar5;
      iVar2 = iVar2 + 0x4c;
    } while (uVar5 < uVar1);
  }
  iVar2 = 3;
  *(undefined4 *)(uVar1 * 0x4c + -0x1c + param_1[0x11]) = 0;
  puVar4 = param_1 + 0x13;
  do {
    uVar3 = FUN_00646b30(uVar1 * 0x10,0x10);
    puVar4[3] = uVar3;
    *puVar4 = uVar3;
    puVar4 = puVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 3;
  *(undefined4 *)param_1[0x11] = 0;
  piVar6 = param_1 + 0x13;
  do {
    *(undefined4 *)((int)piVar6 + param_1[0x11] + (-0x1c - (int)param_1)) = 0;
    iVar2 = iVar2 + -1;
    *(undefined4 *)((int)piVar6 + param_1[0x11] + (-0x10 - (int)param_1)) = 1;
    *(undefined4 *)*piVar6 = 0;
    *(undefined4 *)(*piVar6 + 4) = 0;
    *(undefined4 *)(*piVar6 + 8) = param_1[2];
    *(undefined4 *)(*piVar6 + 0xc) = 0;
    piVar6 = piVar6 + 1;
  } while (iVar2 != 0);
  *param_1 = &PTR_FUN_00803f90;
  return param_1;
}

