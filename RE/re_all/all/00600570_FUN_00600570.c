
undefined4 FUN_00600570(int param_1,LPWSTR param_2)

{
  int *piVar1;
  
  if (param_2 == (LPWSTR)0x0) {
    return 0x80004003;
  }
  if (*(LPCWSTR *)(param_1 + 0x30) == (LPCWSTR)0x0) {
    *param_2 = L'\0';
  }
  else {
    lstrcpynW(param_2,*(LPCWSTR *)(param_1 + 0x30),0x80);
  }
  *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_1 + 0x34);
  piVar1 = *(int **)(param_1 + 0x34);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return 0;
}

