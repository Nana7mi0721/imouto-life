
void __thiscall FUN_00620350(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 local_14 [4];
  int local_10;
  int local_c;
  undefined4 *local_8;
  char local_4;
  
  if (*param_1 != 0) {
    iVar3 = param_1[3];
    local_4 = '\x01';
    local_8 = (undefined4 *)0x0;
    local_10 = 0;
    local_c = 0;
    if (0 < iVar3) {
      if (iVar3 == 0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = (undefined4 *)FUN_00646b30(iVar3 * 4,0x10);
      }
      iVar2 = 0;
      if (0 < local_10) {
        puVar4 = puVar1;
        do {
          if (puVar4 != (undefined4 *)0x0) {
            *puVar4 = local_8[iVar2];
          }
          iVar2 = iVar2 + 1;
          puVar4 = puVar4 + 1;
        } while (iVar2 < local_10);
      }
      if ((local_8 != (undefined4 *)0x0) && (local_4 != '\0')) {
        FUN_00646b80(local_8);
      }
      local_c = iVar3;
      local_8 = puVar1;
    }
    local_4 = '\x01';
    iVar3 = *param_1;
    if (*(int *)(iVar3 + 0x28) == 0) {
      if (local_10 == local_c) {
        iVar2 = local_10 * 2;
        if (local_10 == 0) {
          iVar2 = 1;
        }
        FUN_0078e010(iVar2);
      }
      if (local_8 + local_10 != (int *)0x0) {
        local_8[local_10] = iVar3;
      }
      local_10 = local_10 + 1;
    }
    else {
      FUN_006200c0(param_1,*(undefined4 *)(iVar3 + 0x24),local_14,0xfffffffe);
      FUN_006200c0(param_1,*(undefined4 *)(iVar3 + 0x28),local_14,0xfffffffe);
      FUN_00646b80(param_1[1]);
      param_1[1] = iVar3;
    }
    iVar3 = FUN_006204a0(param_1,local_14,param_2);
    *param_1 = iVar3;
    if ((local_8 != (undefined4 *)0x0) && (local_4 != '\0')) {
      FUN_00646b80(local_8);
    }
  }
  return;
}

