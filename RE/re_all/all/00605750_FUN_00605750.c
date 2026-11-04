
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_00605750(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *unaff_ESI;
  int *piVar3;
  undefined4 uVar4;
  int *piStack_10;
  undefined4 *puStack_c;
  
  piVar1 = param_4;
  puStack_c = &param_4;
  piStack_10 = &DAT_0085e5a4;
  uVar4 = 1;
  piVar3 = (int *)&DAT_0085e894;
  *param_4 = 0;
  iVar2 = (*DAT_00aba190)(&DAT_0085e894,param_1,1);
  if (-1 < iVar2) {
    iVar2 = (**(code **)*unaff_ESI)(unaff_ESI,&DAT_0085e8c4);
    if (iVar2 < 0) {
      (**(code **)(*piStack_10 + 8))(piStack_10);
      return iVar2;
    }
    iVar2 = (**(code **)(*piVar3 + 0xc))(piVar3,param_1,uVar4);
    (**(code **)(*unaff_ESI + 8))(unaff_ESI);
    if (iVar2 < 0) {
      (*(code *)piStack_10[2])(&piStack_10);
      return iVar2;
    }
    *piVar1 = (int)&piStack_10;
    iVar2 = 0;
  }
  return iVar2;
}

