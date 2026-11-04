
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00564510(uint param_1)

{
  uint uVar1;
  
  if (((-1 < (int)param_1) && ((param_1 & 0x7c000000) == 0x24000000)) &&
     (uVar1 = param_1 & 0xffff, uVar1 < 0x100)) {
    if (((&DAT_00aa84b8)[uVar1 * 0x17] != 0) &&
       ((&DAT_00aa84bc)[uVar1 * 0x17] * 0x10000 == (param_1 & 0x3ff0000))) {
      if (*(int *)(&DAT_00aa84e0 + uVar1 * 0x5c) != 0) {
        FUN_0056e1d0(*(int *)(&DAT_00aa84e0 + uVar1 * 0x5c));
      }
      FUN_0056d380(&DAT_00aa84b8 + uVar1 * 0x17,0,0x5c);
      if (DAT_00aa84b0 == param_1) {
        DAT_00aa84b0 = 0xffffffff;
      }
      uVar1 = 0;
      do {
        if ((&DAT_00aa84b8)[(uVar1 & 0xffff) * 0x17] != 0) {
          if (uVar1 != 0x100) {
            return 0;
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 != 0x100);
      DAT_00aa7008 = 0;
      uVar1 = (uint)(DAT_00aa7004 != 0);
      if (uVar1 != DAT_00aa700c) {
        if (DAT_00aba1bc != (code *)0x0) {
          (*DAT_00aba1bc)(DAT_00a20bec,uVar1);
        }
        DAT_00aa700c = uVar1;
        if (uVar1 == 0) {
          FUN_0056e1d0(DAT_00aa6ffc);
          DAT_00aa6ffc = 0;
          DAT_00aa7000 = 0;
          FUN_0056d380(&DAT_00aa5ff8,0,0x400);
          _DAT_00aa5ff0 = 0;
        }
      }
      return 0;
    }
  }
  return 0xffffffff;
}

