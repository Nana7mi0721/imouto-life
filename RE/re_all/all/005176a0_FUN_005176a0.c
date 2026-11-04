
bool FUN_005176a0(uint param_1)

{
  int *piVar1;
  
  if (((((DAT_00cc47d0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc47f8)) ||
      ((DAT_00cc4800 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc47d4 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)))) ||
     ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) ||
      ((piVar1[4] != 0 || (*(char *)(piVar1[0x13] + 8) == '\0')))))) {
    return false;
  }
  return *(char *)(piVar1[0x13] + 0x19) != '\0';
}

