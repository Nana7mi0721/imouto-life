
void FUN_006843e0(int *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (*param_2 == 0) {
    iVar1 = FUN_00684890(param_1);
    *param_2 = iVar1;
  }
  puVar4 = (undefined4 *)*param_2;
  *puVar4 = *param_3;
  puVar4[1] = param_3[1];
  puVar4[2] = param_3[2];
  puVar4[3] = param_3[3];
  uVar3 = 0;
  *(undefined1 *)(puVar4 + 4) = *(undefined1 *)(param_3 + 4);
  iVar1 = 1;
  do {
    uVar3 = uVar3 + *(byte *)(iVar1 + (int)param_3);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x11);
  if (((int)uVar3 < 1) || (0x100 < (int)uVar3)) {
    *(undefined4 *)(*param_1 + 0x14) = 9;
    (**(code **)*param_1)(param_1);
  }
  puVar4 = (undefined4 *)(*param_2 + 0x11);
  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar4 = *param_4;
    param_4 = param_4 + 1;
    puVar4 = puVar4 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar4 = *(undefined1 *)param_4;
    param_4 = (undefined4 *)((int)param_4 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  *(undefined1 *)(*param_2 + 0x111) = 0;
  return;
}

