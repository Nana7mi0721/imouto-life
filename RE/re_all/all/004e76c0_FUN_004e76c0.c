
undefined4 __thiscall FUN_004e76c0(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar2 = (undefined4 *)FUN_004e1fc0();
  local_c = *puVar2;
  local_8 = *(undefined4 *)(param_1 + 4);
  while (pcVar3 = (char *)FUN_004dd3c0(local_c), *pcVar3 == '\0') {
    uVar5 = param_2;
    uVar4 = FUN_004dd3d0(local_c,param_2);
    cVar1 = FUN_004d59a0(uVar4,uVar5);
    if (cVar1 == '\0') {
      local_8 = local_c;
      puVar2 = (undefined4 *)FUN_004e8ab0(local_c);
      local_c = *puVar2;
    }
    else {
      puVar2 = (undefined4 *)FUN_004d6880(local_c);
      local_c = *puVar2;
    }
  }
  return local_8;
}

