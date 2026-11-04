
undefined1 FUN_0068b410(int *param_1)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  char cVar3;
  
  puVar2 = (undefined4 *)param_1[6];
  if (puVar2[1] == 0) {
    cVar3 = (*(code *)puVar2[3])(param_1);
    if (cVar3 == '\0') {
      *(undefined4 *)(*param_1 + 0x14) = 0x19;
      (**(code **)*param_1)(param_1);
    }
  }
  puVar2[1] = puVar2[1] + -1;
  uVar1 = *(undefined1 *)*puVar2;
  *puVar2 = (undefined1 *)*puVar2 + 1;
  return uVar1;
}

