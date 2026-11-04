
undefined4 __fastcall FUN_00600710(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int *unaff_ESI;
  int *piVar4;
  int local_4;
  
  puVar1 = *(undefined4 **)(param_1 + 0x40);
  if (puVar1 == (undefined4 *)0x0) {
    return 0x80004002;
  }
  piVar4 = (int *)&DAT_0085ead4;
  local_4 = param_1;
  iVar2 = (**(code **)*puVar1)(puVar1,&DAT_0085ead4,&local_4);
  if (iVar2 < 0) {
    uVar3 = (**(code **)(**(int **)(param_1 + 0x40) + 0x20))(*(int **)(param_1 + 0x40),unaff_ESI);
    return uVar3;
  }
  uVar3 = (**(code **)(*piVar4 + 0x4c))(piVar4,unaff_ESI,local_4);
  (**(code **)(*unaff_ESI + 8))(unaff_ESI);
  return uVar3;
}

