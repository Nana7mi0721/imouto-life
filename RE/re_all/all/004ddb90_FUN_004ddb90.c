
void __thiscall FUN_004ddb90(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 local_8;
  
  local_8 = param_2;
  while( true ) {
    pcVar2 = (char *)FUN_004dd3c0(local_8,param_1);
    if (*pcVar2 != '\0') break;
    puVar3 = (undefined4 *)FUN_004d6880(local_8);
    FUN_004ddb90(*puVar3);
    puVar3 = (undefined4 *)FUN_004e8ab0(local_8);
    uVar1 = *puVar3;
    FUN_004e7b00(local_8);
    deallocate(local_8,1);
    local_8 = uVar1;
  }
  return;
}

