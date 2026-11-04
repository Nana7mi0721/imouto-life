
void FUN_005ee580(void)

{
  int iVar1;
  undefined4 *unaff_EBX;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  if (0 < (int)unaff_EBX[10]) {
    piVar3 = unaff_EBX + 2;
    do {
      iVar1 = *piVar3;
      if (iVar1 == 0) {
        iVar1 = -1;
      }
      FUN_00516bd0(iVar2,iVar1);
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < (int)unaff_EBX[10]);
  }
  FUN_00516cc0(*unaff_EBX);
  FUN_00516d40(unaff_EBX[1]);
  return;
}

