
undefined4 __thiscall FUN_004e2030(int param_1,undefined4 param_2,undefined4 param_3)

{
  char *pcVar1;
  byte *pbVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 local_18;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b16b0;
  pvStack_10 = ExceptionList;
  local_18 = *(undefined4 *)(param_1 + 4);
  ExceptionList = &pvStack_10;
  pcVar1 = (char *)FUN_004d6860(param_2);
  if (*pcVar1 == '\0') {
    pbVar2 = (byte *)FUN_004d6850(param_2);
    uVar6 = (uint)*pbVar2;
    uVar3 = FUN_004e06e0(param_2,uVar6);
    uVar3 = FUN_004e2210(*(undefined4 *)(param_1 + 4),param_3,*(undefined4 *)(param_1 + 4),uVar3,
                         uVar6);
    pcVar1 = (char *)FUN_004d6860(local_18);
    if (*pcVar1 != '\0') {
      local_18 = uVar3;
    }
    local_8 = 0;
    puVar4 = (undefined4 *)FUN_004e8ab0(param_2);
    uVar5 = FUN_004e2030(*puVar4,uVar3);
    puVar4 = (undefined4 *)FUN_004e8ab0(uVar3);
    *puVar4 = uVar5;
    puVar4 = (undefined4 *)FUN_004d6880(param_2);
    uVar5 = FUN_004e2030(*puVar4,uVar3);
    puVar4 = (undefined4 *)FUN_004d6880(uVar3);
    *puVar4 = uVar5;
  }
  ExceptionList = pvStack_10;
  return local_18;
}

