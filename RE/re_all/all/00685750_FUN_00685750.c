
void FUN_00685750(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char *_Src;
  int iVar4;
  int local_4;
  
  piVar1 = param_1;
  param_1[1] = 0;
  local_4 = FUN_006877c0(param_1);
  puVar2 = (undefined4 *)FUN_00687650(piVar1,0x54);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_0065f670(piVar1);
    *(undefined4 *)(*piVar1 + 0x14) = 0x38;
    *(undefined4 *)(*piVar1 + 0x18) = 0;
    (**(code **)*piVar1)(piVar1);
  }
  *puVar2 = FUN_00685890;
  puVar2[1] = FUN_006859e0;
  puVar2[2] = FUN_00685a90;
  puVar2[3] = FUN_00685b40;
  puVar2[4] = FUN_00685bf0;
  puVar2[5] = FUN_00685c60;
  puVar2[6] = &LAB_00685cd0;
  puVar2[7] = &LAB_00685e50;
  puVar2[8] = &LAB_00686040;
  puVar2[9] = FUN_00686240;
  puVar2[10] = &LAB_00686340;
  puVar2[0xc] = 1000000000;
  iVar4 = 2;
  puVar2[0xb] = local_4;
  puVar3 = puVar2 + 0x10;
  do {
    puVar3[-2] = 0;
    *puVar3 = 0;
    puVar3 = puVar3 + -1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  puVar2[0x11] = 0;
  puVar2[0x12] = 0;
  puVar2[0x13] = 0x54;
  piVar1[1] = (int)puVar2;
  _Src = _getenv(s_JPEGMEM_00a0ef50);
  if (_Src != (char *)0x0) {
    param_1 = (int *)CONCAT31(param_1._1_3_,0x78);
    iVar4 = _sscanf(_Src,s__ld_c_00a0ef48,&local_4,&param_1);
    if (0 < iVar4) {
      if (((char)param_1 == 'm') || ((char)param_1 == 'M')) {
        puVar2[0xb] = local_4 * 1000000;
        return;
      }
      puVar2[0xb] = local_4 * 1000;
    }
  }
  return;
}

