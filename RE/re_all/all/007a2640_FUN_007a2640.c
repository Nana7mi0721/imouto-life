
undefined * FUN_007a2640(int param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  undefined **ppuVar3;
  int local_4;
  
  local_4 = 0;
  ppuVar3 = &PTR_DAT_0083c474;
  do {
    piVar1 = (int *)*ppuVar3;
    iVar2 = 0;
    do {
      if ((param_1 == *piVar1) && (param_2 << ((byte)iVar2 & 0x1f) == piVar1[0xb] * piVar1[10])) {
        if (param_3 != (undefined4 *)0x0) {
          *param_3 = 0;
        }
        return (&PTR_DAT_0083c474)[local_4];
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
    ppuVar3 = ppuVar3 + 1;
    local_4 = local_4 + 1;
    if (0x83c477 < (int)ppuVar3) {
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = 0xffffffff;
      }
      return (undefined *)0x0;
    }
  } while( true );
}

