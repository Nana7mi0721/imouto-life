
undefined4 FUN_005fcad0(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((int *)param_1[4] == (int *)0x0) {
    return 0xffffffff;
  }
  iVar2 = (**(code **)(*(int *)param_1[4] + 0x50))();
  while (iVar2 = iVar2 + -1, -1 < iVar2) {
    puVar3 = (undefined4 *)(**(code **)(*(int *)param_1[4] + 0x58))(iVar2);
    (**(code **)(*(int *)param_1[4] + 0x28))(puVar3);
    if (puVar3 != (undefined4 *)0x0) {
      (**(code **)*puVar3)(1);
    }
  }
  iVar2 = *(int *)(param_1[4] + 8);
  while (iVar2 = iVar2 + -1, -1 < iVar2) {
    piVar1 = *(int **)(*(int *)(param_1[4] + 0x10) + iVar2 * 4);
    if (((piVar1[0x3a] == 2) && (piVar1 != (int *)0x0)) &&
       ((undefined4 *)piVar1[0x7a] != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)piVar1[0x7a])(1);
    }
    (**(code **)(*(int *)param_1[4] + 0x14))(piVar1);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(1);
    }
  }
  if ((undefined4 *)param_1[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[5])(1);
    param_1[5] = 0;
  }
  if ((undefined4 *)param_1[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[4])(1);
    param_1[4] = 0;
  }
  if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[3])(1);
    param_1[3] = 0;
  }
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[2])(1);
    param_1[2] = 0;
  }
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1])(1);
    param_1[1] = 0;
  }
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*param_1)(1);
    *param_1 = 0;
  }
  return 0;
}

