
undefined4 __thiscall FUN_004ea630(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar2 = (undefined4 *)FUN_004e1fc0();
  local_c = *puVar2;
  local_8 = *(undefined4 *)(param_1 + 4);
  while (pcVar3 = (char *)FUN_004d6860(local_c), *pcVar3 == '\0') {
    uVar4 = FUN_004d52c0(local_c);
    cVar1 = FUN_004d59a0(param_2,uVar4);
    if (cVar1 == '\0') {
      puVar2 = (undefined4 *)FUN_004d6880(local_c);
      local_c = *puVar2;
    }
    else {
      local_8 = local_c;
      puVar2 = (undefined4 *)FUN_004e8ab0(local_c);
      local_c = *puVar2;
    }
  }
  return local_8;
}

