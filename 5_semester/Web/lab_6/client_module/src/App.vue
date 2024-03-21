<template>
  <router-view/>
</template>

<script>
export default {
  name: 'App'
}
</script>

<style>
  * {
    padding: 0px;
    margin: 0px;
  }

  body {
    width: 100%;
    min-height: 100vh;
    background-color: #131B23;
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: center;
  }

  #app {
    font-family: Avenir, Helvetica, Arial, sans-serif;
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
    text-align: center;
    color: #2c3e50;
  }
</style>
