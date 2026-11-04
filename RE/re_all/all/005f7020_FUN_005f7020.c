
int * FUN_005f7020(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int **ppiVar5;
  int *piStack_20;
  int *piStack_1c;
  undefined4 uStack_18;
  int *piStack_14;
  int *piStack_10;
  int local_8;
  int iStack_4;
  
  piStack_10 = &local_8;
  piStack_14 = param_1;
  uStack_18 = 0x5f7033;
  (**(code **)(*param_1 + 0x28))();
  piVar2 = piStack_10;
  piStack_1c = &iStack_4;
  uStack_18 = 0;
  piStack_20 = (int *)0x1;
  iVar4 = (**(code **)(*piStack_10 + 0xc))();
  piVar3 = piStack_10;
  piVar1 = piStack_14;
  while( true ) {
    piStack_14 = piVar1;
    if (iVar4 != 0) {
      (**(code **)(*piStack_20 + 8))(piStack_20);
      return (int *)0x0;
    }
    ppiVar5 = &piStack_1c;
    (**(code **)(*piVar1 + 0x24))();
    if (piVar2 == piVar3) break;
    (**(code **)(*piStack_1c + 8))(piStack_1c);
    iVar4 = (**(code **)(*piVar1 + 0xc))(piVar1,1,&piStack_20,0);
    piVar1 = piStack_14;
  }
  (*(code *)(*ppiVar5)[2])(ppiVar5);
  return piStack_20;
}

