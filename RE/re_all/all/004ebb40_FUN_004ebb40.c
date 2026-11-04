
void __fastcall FUN_004ebb40(int *param_1)

{
  char *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  pcVar1 = (char *)FUN_004dd3c0(*param_1);
  if (*pcVar1 == '\0') {
    puVar2 = (undefined4 *)FUN_004d6880(*param_1);
    pcVar1 = (char *)FUN_004dd3c0(*puVar2);
    if (*pcVar1 == '\0') {
      puVar2 = (undefined4 *)FUN_004d6880(*param_1);
      iVar3 = FUN_004e78c0(*puVar2);
      *param_1 = iVar3;
    }
    else {
      while( true ) {
        piVar4 = (int *)FUN_004d6870(*param_1);
        iVar3 = *piVar4;
        pcVar1 = (char *)FUN_004dd3c0(iVar3);
        if ((*pcVar1 != '\0') || (piVar4 = (int *)FUN_004d6880(iVar3), *param_1 != *piVar4)) break;
        *param_1 = iVar3;
      }
      *param_1 = iVar3;
    }
  }
  return;
}

