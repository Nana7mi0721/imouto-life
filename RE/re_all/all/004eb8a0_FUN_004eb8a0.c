
void __fastcall FUN_004eb8a0(int *param_1)

{
  char *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  pcVar1 = (char *)FUN_004e06d0(*param_1);
  if (*pcVar1 == '\0') {
    puVar3 = (undefined4 *)FUN_004e8ab0(*param_1);
    pcVar1 = (char *)FUN_004e06d0(*puVar3);
    if (*pcVar1 == '\0') {
      puVar3 = (undefined4 *)FUN_004e8ab0(*param_1);
      iVar4 = FUN_004eb980(*puVar3);
      *param_1 = iVar4;
    }
    else {
      while( true ) {
        piVar2 = (int *)FUN_004d6870(*param_1);
        iVar4 = *piVar2;
        pcVar1 = (char *)FUN_004e06d0(iVar4);
        if (*pcVar1 != '\0') break;
        piVar2 = (int *)FUN_004e8ab0(iVar4);
        if (*param_1 != *piVar2) break;
        *param_1 = iVar4;
      }
      pcVar1 = (char *)FUN_004e06d0(iVar4);
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

