
void __fastcall FUN_004eaa90(int *param_1)

{
  char *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  pcVar1 = (char *)FUN_004d6860(*param_1);
  if (*pcVar1 == '\0') {
    puVar3 = (undefined4 *)FUN_004e8ab0(*param_1);
    pcVar1 = (char *)FUN_004d6860(*puVar3);
    if (*pcVar1 == '\0') {
      puVar3 = (undefined4 *)FUN_004e8ab0(*param_1);
      iVar4 = FUN_004e8a30(*puVar3);
      *param_1 = iVar4;
    }
    else {
      while( true ) {
        piVar2 = (int *)FUN_004d6870(*param_1);
        iVar4 = *piVar2;
        pcVar1 = (char *)FUN_004d6860(iVar4);
        if (*pcVar1 != '\0') break;
        piVar2 = (int *)FUN_004e8ab0(iVar4);
        if (*param_1 != *piVar2) break;
        *param_1 = iVar4;
      }
      pcVar1 = (char *)FUN_004d6860(iVar4);
      if (*pcVar1 == '\0') {
        *param_1 = iVar4;
      }
    }
  }
  else {
    piVar2 = (int *)FUN_004d6880(*param_1);
    *param_1 = *piVar2;
  }
  return;
}

