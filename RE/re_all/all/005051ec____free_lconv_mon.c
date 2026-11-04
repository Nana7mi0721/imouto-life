
/* Library Function - Single Match
    ___free_lconv_mon
   
   Library: Visual Studio 2003 Release */

void ___free_lconv_mon(int param_1)

{
  undefined *puVar1;
  
  if (param_1 != 0) {
    puVar1 = *(undefined **)(param_1 + 0xc);
    if ((puVar1 != *(undefined **)(PTR_PTR_0084be44 + 0xc)) && (puVar1 != PTR_DAT_0084be20)) {
      _free(puVar1);
    }
    puVar1 = *(undefined **)(param_1 + 0x10);
    if ((puVar1 != *(undefined **)(PTR_PTR_0084be44 + 0x10)) && (puVar1 != PTR_DAT_0084be24)) {
      _free(puVar1);
    }
    puVar1 = *(undefined **)(param_1 + 0x14);
    if ((puVar1 != *(undefined **)(PTR_PTR_0084be44 + 0x14)) && (puVar1 != PTR_DAT_0084be28)) {
      _free(puVar1);
    }
    puVar1 = *(undefined **)(param_1 + 0x18);
    if ((puVar1 != *(undefined **)(PTR_PTR_0084be44 + 0x18)) && (puVar1 != PTR_DAT_0084be2c)) {
      _free(puVar1);
    }
    puVar1 = *(undefined **)(param_1 + 0x1c);
    if ((puVar1 != *(undefined **)(PTR_PTR_0084be44 + 0x1c)) && (puVar1 != PTR_DAT_0084be30)) {
      _free(puVar1);
    }
    puVar1 = *(undefined **)(param_1 + 0x20);
    if ((puVar1 != *(undefined **)(PTR_PTR_0084be44 + 0x20)) && (puVar1 != PTR_DAT_0084be34)) {
      _free(puVar1);
    }
    puVar1 = *(undefined **)(param_1 + 0x24);
    if ((puVar1 != *(undefined **)(PTR_PTR_0084be44 + 0x24)) && (puVar1 != PTR_DAT_0084be38)) {
      _free(puVar1);
    }
  }
  return;
}

