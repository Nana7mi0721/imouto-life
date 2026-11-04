
int FUN_006a9070(int param_1,int *param_2,undefined4 *param_3,uint param_4,int param_5,code *param_6
                ,int param_7,int param_8)

{
  int *piVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *local_8;
  int local_4;
  
  pcVar3 = param_6;
  iVar6 = param_1;
  if ((param_1 == 0) || (param_6 == (code *)0x0)) {
    local_4 = -1;
  }
  else {
    local_4 = (*param_6)(param_1,0,0,1);
  }
  piVar1 = param_2;
  local_8 = (undefined4 *)0x0;
  param_1 = 0;
  piVar7 = param_2;
  for (iVar8 = 0xb4; iVar8 != 0; iVar8 = iVar8 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  *param_2 = iVar6;
  param_2[0xb0] = param_5;
  param_2[0xb1] = (int)pcVar3;
  piVar7 = param_2 + 6;
  param_2[0xb2] = param_7;
  param_2[0xb3] = param_8;
  FUN_006a86a0(piVar7);
  uVar2 = param_4;
  puVar10 = param_3;
  if (param_3 != (undefined4 *)0x0) {
    puVar4 = (undefined4 *)FUN_006a8700(piVar7,param_4);
    for (uVar9 = uVar2 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar4 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar4 = puVar4 + 1;
    }
    for (uVar9 = uVar2 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)puVar10;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    FUN_006a87a0(piVar7,uVar2);
  }
  if (local_4 != -1) {
    piVar1[1] = 1;
  }
  piVar1[0xd] = 1;
  pvVar5 = _calloc(1,0x20);
  piVar1[0x12] = (int)pvVar5;
  pvVar5 = _calloc(piVar1[0xd],0x10);
  piVar1[0x13] = (int)pvVar5;
  FUN_006a83f0(piVar1 + 0x1e,0xffffffff);
  iVar6 = FUN_006a9220(piVar1,piVar1[0x12],piVar1[0x13],&local_8,&param_1,0);
  if (iVar6 < 0) {
    *piVar1 = 0;
    FUN_006a8f20(piVar1);
  }
  else {
    piVar7 = _calloc(param_1 + 2,4);
    piVar1[0x10] = (int)piVar7;
    piVar1[0x17] = piVar1[0x72];
    *piVar7 = piVar1[0x72];
    *(int *)(piVar1[0x10] + 4) = param_1;
    puVar10 = local_8;
    puVar4 = (undefined4 *)(piVar1[0x10] + 8);
    for (iVar8 = param_1; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar4 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar4 = puVar4 + 1;
    }
    pvVar5 = _calloc(1,8);
    piVar1[0xe] = (int)pvVar5;
    pvVar5 = _calloc(1,8);
    puVar10 = (undefined4 *)piVar1[0xe];
    piVar1[0xf] = (int)pvVar5;
    *puVar10 = 0;
    puVar10[1] = 0;
    piVar7 = (int *)piVar1[0xf];
    *piVar7 = piVar1[2];
    piVar7[1] = piVar1[3];
    piVar1[0x16] = 1;
  }
  if (local_8 != (undefined4 *)0x0) {
    _free(local_8);
  }
  return iVar6;
}

