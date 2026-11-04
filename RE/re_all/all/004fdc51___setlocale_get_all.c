
/* Library Function - Single Match
    __setlocale_get_all
   
   Library: Visual Studio 2003 Release */

undefined1 * __setlocale_get_all(void)

{
  bool bVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  
  bVar1 = true;
  if (DAT_0084b66c == (undefined1 *)0x0) {
    DAT_0084b66c = _malloc(0x351);
    if (DAT_0084b66c == (undefined1 *)0x0) {
      return (undefined1 *)0x0;
    }
  }
  *DAT_0084b66c = 0;
  __strcats(DAT_0084b66c,3,PTR_s_LC_COLLATE_0084b674,&DAT_007d2600,PTR_DAT_0084b678);
  ppuVar3 = &PTR_DAT_0084b678;
  do {
    FUN_004fd710(DAT_0084b66c,&DAT_007d25fc);
    ppuVar4 = ppuVar3 + 3;
    iVar2 = _strcmp(*ppuVar3,*ppuVar4);
    if (iVar2 != 0) {
      bVar1 = false;
    }
    __strcats(DAT_0084b66c,3,ppuVar3[2],&DAT_007d2600,*ppuVar4);
    ppuVar3 = ppuVar4;
  } while ((int)ppuVar4 < 0x84b6a8);
  if (bVar1) {
    _free(DAT_0084b66c);
    DAT_0084b66c = (undefined1 *)0x0;
    return PTR_DAT_0084b684;
  }
  return DAT_0084b66c;
}

