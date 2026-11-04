
/* WARNING: Removing unreachable block (ram,0x004d37b9) */

undefined4 __thiscall FUN_004d3720(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined4 local_3c;
  undefined1 local_31;
  undefined1 local_30 [7];
  undefined1 local_29;
  undefined1 local_28 [7];
  undefined1 local_21;
  undefined1 local_20 [12];
  undefined1 local_14 [4];
  undefined4 local_10;
  undefined4 local_c;
  char local_5;
  
  puVar2 = (undefined4 *)FUN_004e1fc0();
  local_10 = *puVar2;
  local_c = *(undefined4 *)(param_1 + 4);
  local_5 = '\x01';
  while (pcVar3 = (char *)FUN_004dd3c0(local_10), *pcVar3 == '\0') {
    local_c = local_10;
    uVar4 = FUN_004dd3d0(local_10);
    uVar5 = FUN_004e8ab0(param_3,uVar4);
    local_5 = FUN_004d59a0(uVar5,uVar4);
    if (local_5 == '\0') {
      puVar2 = (undefined4 *)FUN_004d6880(local_10);
      local_3c = *puVar2;
    }
    else {
      puVar2 = (undefined4 *)FUN_004e8ab0(local_10);
      local_3c = *puVar2;
    }
    local_10 = local_3c;
  }
  FUN_004e92a0(local_c);
  if (local_5 != '\0') {
    uVar4 = FUN_004cc870(local_20);
    cVar1 = const_iterator__operator__(uVar4);
    if (cVar1 != '\0') {
      local_21 = 1;
      puVar6 = &local_21;
      uVar4 = FUN_004ddc10(local_28,1,local_c,param_3);
      FUN_004dea90(uVar4,puVar6);
      return param_2;
    }
    FUN_004dea10();
  }
  uVar4 = FUN_004e8ab0(param_3);
  uVar5 = FUN_004e9610(uVar4);
  uVar5 = FUN_004dd3d0(uVar5);
  cVar1 = FUN_004d59a0(uVar5,uVar4);
  if (cVar1 == '\0') {
    local_31 = 0;
    FUN_004dea90(local_14,&local_31);
  }
  else {
    local_29 = 1;
    puVar6 = &local_29;
    uVar4 = FUN_004ddc10(local_30,CONCAT31((int3)((uint)puVar6 >> 8),local_5),local_c,param_3);
    FUN_004dea90(uVar4,puVar6);
  }
  return param_2;
}

