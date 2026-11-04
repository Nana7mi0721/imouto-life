
uint FUN_0067db00(int *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar2 = param_1[1];
  uVar3 = uVar2;
  if (param_3 < uVar2) {
    uVar3 = param_3;
  }
  if (uVar3 == 0) {
    return 0;
  }
  param_1[1] = uVar2 - uVar3;
  puVar4 = (undefined4 *)*param_1;
  puVar5 = param_2;
  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  for (uVar2 = uVar3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  if (*(int *)(param_1[7] + 0x18) == 1) {
    iVar1 = FUN_0067c870(param_1[0xc],param_2,uVar3);
  }
  else {
    if (*(int *)(param_1[7] + 0x18) != 2) goto LAB_0067db6d;
    iVar1 = FUN_0067c560(param_1[0xc],param_2,uVar3);
  }
  param_1[0xc] = iVar1;
LAB_0067db6d:
  param_1[2] = param_1[2] + uVar3;
  *param_1 = *param_1 + uVar3;
  return uVar3;
}

