
void __thiscall FUN_0049b6c0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar2 = FUN_004ce080();
  if (iVar2 <= *(int *)(param_1 + 100)) {
    FUN_004ce970(*(int *)(param_1 + 100) + 1);
    puVar3 = (undefined4 *)FUN_004ce990(*(undefined4 *)(param_1 + 100));
    *puVar3 = 0;
  }
  iVar2 = FUN_004ce080();
  if (iVar2 <= *(int *)(param_1 + 100)) {
    FUN_004ce970(*(int *)(param_1 + 100) + 1);
    puVar3 = (undefined4 *)FUN_004ce990(*(undefined4 *)(param_1 + 100));
    *puVar3 = 0;
  }
  iVar2 = FUN_004ce080();
  if (iVar2 <= *(int *)(param_1 + 100)) {
    FUN_004ce970(*(int *)(param_1 + 100) + 1);
    puVar3 = (undefined4 *)FUN_004ce990(*(undefined4 *)(param_1 + 100));
    *puVar3 = 0;
  }
  iVar2 = FUN_004ce080();
  if (iVar2 <= *(int *)(param_1 + 100)) {
    FUN_004ce970(*(int *)(param_1 + 100) + 1);
    puVar3 = (undefined4 *)FUN_004ce990(*(undefined4 *)(param_1 + 100));
    *puVar3 = 0;
  }
  piVar4 = (int *)FUN_004ce990(*(undefined4 *)(param_1 + 100));
  if (*piVar4 < (*(int *)(param_1 + 0x5c) << 1) / *(int *)(param_1 + 0x100)) {
    iVar2 = *(int *)(param_1 + 0x5c);
    iVar1 = *(int *)(param_1 + 0x100);
    piVar4 = (int *)FUN_004ce990(*(undefined4 *)(param_1 + 100));
    *piVar4 = (iVar2 << 1) / iVar1;
    puVar3 = (undefined4 *)FUN_004ce990(*(undefined4 *)(param_1 + 100));
    *puVar3 = *(undefined4 *)(param_1 + 0x5c);
    piVar4 = (int *)FUN_004ce990(*(undefined4 *)(param_1 + 100));
    if (*piVar4 < *(int *)(param_1 + 0xf0)) {
      local_c = *(undefined4 *)(param_1 + 0xf0);
    }
    else {
      puVar3 = (undefined4 *)FUN_004ce990(*(undefined4 *)(param_1 + 100));
      local_c = *puVar3;
    }
    *(undefined4 *)(param_1 + 0xf0) = local_c;
    piVar4 = (int *)FUN_004ce990(*(undefined4 *)(param_1 + 100));
    if (*piVar4 < *(int *)(param_1 + 0xf4)) {
      local_10 = *(undefined4 *)(param_1 + 0xf4);
    }
    else {
      puVar3 = (undefined4 *)FUN_004ce990(*(undefined4 *)(param_1 + 100));
      local_10 = *puVar3;
    }
    *(undefined4 *)(param_1 + 0xf4) = local_10;
  }
  iVar2 = *(int *)(param_1 + 0x60);
  iVar1 = *(int *)(param_1 + 0x100);
  piVar4 = (int *)FUN_004ce990(*(undefined4 *)(param_1 + 100));
  *piVar4 = (iVar2 << 1) / iVar1;
  puVar3 = (undefined4 *)FUN_004ce990(*(undefined4 *)(param_1 + 100));
  *puVar3 = param_2;
  return;
}

