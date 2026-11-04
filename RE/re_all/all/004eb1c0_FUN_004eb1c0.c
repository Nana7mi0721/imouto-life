
void FUN_004eb1c0(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int *piVar5;
  
  puVar2 = (undefined4 *)FUN_004e8ab0(param_1);
  uVar1 = *puVar2;
  puVar2 = (undefined4 *)FUN_004d6880(uVar1);
  puVar3 = (undefined4 *)FUN_004e8ab0(param_1);
  *puVar3 = *puVar2;
  puVar2 = (undefined4 *)FUN_004d6880(uVar1);
  pcVar4 = (char *)FUN_004d6860(*puVar2);
  if (*pcVar4 == '\0') {
    puVar2 = (undefined4 *)FUN_004d6880(uVar1);
    piVar5 = (int *)FUN_004d6870(*puVar2);
    *piVar5 = param_1;
  }
  puVar2 = (undefined4 *)FUN_004d6870(param_1);
  puVar3 = (undefined4 *)FUN_004d6870(uVar1);
  *puVar3 = *puVar2;
  piVar5 = (int *)FUN_004e1fc0();
  if (param_1 == *piVar5) {
    puVar2 = (undefined4 *)FUN_004e1fc0();
    *puVar2 = uVar1;
  }
  else {
    puVar2 = (undefined4 *)FUN_004d6870(param_1);
    piVar5 = (int *)FUN_004d6880(*puVar2);
    if (param_1 == *piVar5) {
      puVar2 = (undefined4 *)FUN_004d6870(param_1);
      puVar2 = (undefined4 *)FUN_004d6880(*puVar2);
      *puVar2 = uVar1;
    }
    else {
      puVar2 = (undefined4 *)FUN_004d6870(param_1);
      puVar2 = (undefined4 *)FUN_004e8ab0(*puVar2);
      *puVar2 = uVar1;
    }
  }
  piVar5 = (int *)FUN_004d6880(uVar1);
  *piVar5 = param_1;
  puVar2 = (undefined4 *)FUN_004d6870(param_1);
  *puVar2 = uVar1;
  return;
}

