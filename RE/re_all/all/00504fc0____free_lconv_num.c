
/* Library Function - Single Match
    ___free_lconv_num
   
   Library: Visual Studio 2003 Release */

void ___free_lconv_num(undefined4 *param_1)

{
  undefined *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined *)*param_1;
    if ((puVar1 != *(undefined **)PTR_PTR_0084be44) && (puVar1 != PTR_DAT_0084be14)) {
      _free(puVar1);
    }
    puVar1 = (undefined *)param_1[1];
    if ((puVar1 != *(undefined **)(PTR_PTR_0084be44 + 4)) && (puVar1 != PTR_DAT_0084be18)) {
      _free(puVar1);
    }
    puVar1 = (undefined *)param_1[2];
    if ((puVar1 != *(undefined **)(PTR_PTR_0084be44 + 8)) && (puVar1 != PTR_DAT_0084be1c)) {
      _free(puVar1);
    }
  }
  return;
}

